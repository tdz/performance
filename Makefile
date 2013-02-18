
# Files

PDF_FILES = presentation.pdf

presentation.pdf : algo.tex \
                   highlevel.tex \
                   lowlevel.tex \
                   presentation.tex \
                   workshop.tex

# Tools

PDFLATEX := pdflatex
PDFLATEXFLAGS := -halt-on-error

RM := rm -f

# Rules

.PHONY: all clean
.SUFFIXES: .pdf .tex

all: $(PDF_FILES)

clean:
	$(RM) $(PDF_FILES)
	$(RM) *.aux
	$(RM) *.log
	$(RM) *.nav
	$(RM) *.out
	$(RM) *.snm
	$(RM) *.toc

%.pdf:
	$(PDFLATEX) $(PDFLATEXFLAGS) -output-format pdf $(basename $@)
	$(PDFLATEX) $(PDFLATEXFLAGS) -output-format pdf $(basename $@)
	$(PDFLATEX) $(PDFLATEXFLAGS) -output-format pdf $(basename $@)
