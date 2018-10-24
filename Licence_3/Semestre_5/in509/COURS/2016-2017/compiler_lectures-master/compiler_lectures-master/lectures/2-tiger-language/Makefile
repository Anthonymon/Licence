SRCS = $(wildcard *.md)
ALL_PDF = $(patsubst %.md,%.pdf,$(SRCS))

all: pdf

pdf: $(ALL_PDF)

%.tex: %.md
	pandoc -s --chapters -t beamer -f markdown $< -o $@

%.pdf: %.tex
	pdflatex $<

clean:
	rm -f $(ALL_PDF) *.snm *.toc *.out *.nav *.aux *.log *.ps *.dvi temp_* *.tmp *.vrb *.tex
