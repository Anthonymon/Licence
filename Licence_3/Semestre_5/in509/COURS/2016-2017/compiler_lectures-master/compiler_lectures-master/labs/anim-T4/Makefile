all:
	for i in *svg; do inkscape --export-dpi=300 -e $i.png $i ; done
	convert -delay 300 -dispose Background 1.svg.png 2.svg.png 3.svg.png 5.svg.png 6.svg.png 7.svg.png 8.svg.png 9.svg.png 10.svg.png 11.svg.png 12.svg.png 13.svg.png 14.svg.png 15.svg.png -loop 1 animation.gif

