
# Files

PDF_FILES = presentation.pdf

presentation.pdf : algo.tex \
                   complexity-gpi.pdf \
                   highlevel.tex \
                   layout-eps.pdf \
                   lowlevel.tex \
                   pipeline-eps.pdf \
                   presentation.tex \
                   workshop.tex

# Tools

EPSTOPDF := epstopdf
EPSTOPDFFLAGS :=
GNUPLOT := gnuplot
PDFLATEX := pdflatex
PDFLATEXFLAGS := -halt-on-error

RM := rm -f

# Rules

.PHONY: all clean
.SUFFIXES: .gpi .pdf .tex

all: $(PDF_FILES)

clean:
	$(RM) $(PDF_FILES)
	$(RM) *.aux
	$(RM) *.log
	$(RM) *.nav
	$(RM) *.out
	$(RM) *.snm
	$(RM) *.toc

%-eps.pdf: %.eps
	$(EPSTOPDF) $(EPSTOPDFFLAGS) --outfile=$@ $^

%-gpi.pdf: %.gpi
	$(GNUPLOT) $^ | $(EPSTOPDF) $(EPSTOPDFFLAGS) --filter --outfile=$@

%.pdf:
	$(PDFLATEX) $(PDFLATEXFLAGS) -output-format pdf $(basename $@)
	$(PDFLATEX) $(PDFLATEXFLAGS) -output-format pdf $(basename $@)
	$(PDFLATEX) $(PDFLATEXFLAGS) -output-format pdf $(basename $@)
