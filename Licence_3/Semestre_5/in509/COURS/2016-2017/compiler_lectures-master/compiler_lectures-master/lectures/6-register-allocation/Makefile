NAME=registres
SVG_IMAGES = cc-logo.pdf 

%.pdf: %.svg
	#convert $< $@
	inkscape --export-pdf=$@ $<

all: $(SVG_IMAGES)
	pdflatex $(NAME).tex
#pdflatex $(NAME).tex

clean:
	rm -rf auto *.lst *.log *.d *.aux *.nav *.out *.snm *.toc *.dvi *.vrb *.xmpi $(NAME).pdf $(SVG_IMAGES)	
