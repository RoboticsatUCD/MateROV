#!/bin/bash

##
# crop		-- crop successive nths of n images vertically
#
# usage		-- crop IMGS
#
# notes		-- assumes images are the same size
#		   writes output images with same names
#
# written	-- 26 November, 2013 by Egan McCOmb
#
# revised	--
##

outdir="./imgout"

usage()
{
	echo "Usage: $(basename $0) IMGS"
}

chkargs()
{
	if (( ! $# ))
	then
		echo "Error: Too few arguments" >&2
		usage
		exit 3
	else
		k=$#
		p=$((100/$#))
	fi
}

hsize()
{
	# For some reason identify -format "%x" is not working.
	off=$(($(identify "$img" | cut -d " " -f 3 | cut -d "x" -f 1)/$k))
}

ncrop()
{
	convert "$img" -crop $p%x0+$n+0 "$outdir"/$(basename "$img")
}

##----MAIN----##
chkargs "$@"

[[ ! -d "$outdir" ]] && mkdir -p "$outdir"

img="$1"
hsize
n=0

for img in "$@"
do
	ncrop
	n=$(($n+$off))
done

exit 0
