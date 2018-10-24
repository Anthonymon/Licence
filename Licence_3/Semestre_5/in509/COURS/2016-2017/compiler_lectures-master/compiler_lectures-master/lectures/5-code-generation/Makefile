SRCS = $(wildcard *.md)
ALL_PDF = $(patsubst %.md,%.pdf,$(SRCS))

all: pdf

pdf: $(ALL_PDF)

%.pdf: %.md
	./do-dot.py $< > $<.md.tmp
	pandoc --include-in-header header.tex --chapters -o full -t beamer -f markdown $<.md.tmp -o $<.tex
	#sed -i 's/\\frametitle/[fragile]\\frametitle/' $<.tex
	pdflatex --shell-escape $<.tex

clean:
	rm -f *.snm *.toc *.out *.nav *.aux *.log *.ps *.dvi temp_* *.tmp *.pyg *.vrb compil-generation4.md.tex *.pdf
