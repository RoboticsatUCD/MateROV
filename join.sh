#!/bin/bash

##
# join		-- join successive nths of n images vertically
#
# usage		-- join IMGS
#
# notes		-- assumes images are compatibly sized
#		   does no drift correction whatsoever
#
# written	-- 26 November, 2013 by Egan McCOmb
#
# revised	--
##

outfile="stitched.jpg"

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
	fi
}

##----MAIN----##
chkargs "$@"

convert +append "$@" "$outfile"

exit 0
