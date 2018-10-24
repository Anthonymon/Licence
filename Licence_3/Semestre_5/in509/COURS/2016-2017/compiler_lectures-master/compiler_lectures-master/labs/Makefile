SRCS = $(wildcard *.md)
ALL_HTML = $(patsubst %.md,%.html,$(SRCS))

all: html 

html: $(ALL_HTML)

%.html: %.md
	pandoc -s -S --toc -c pandoc.css --mathjax -f markdown $< -o $@

%.tex: %.md
	pandoc -s -S --toc -c pandoc.css --mathjax -f markdown $< -o $@

%.pdf: %.tex
	pdflatex $< 
	pdflatex $< 

publish: Projet.pdf Projet.html 
	scp Projet.pdf Projet.html tahiti.prism.uvsq.fr:/var/www/compil/

clean:
	rm $(ALL_HTML) 
