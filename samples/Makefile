SAMPLES := $(patsubst %/,%,$(dir $(wildcard */Makefile)))

.PHONY: $(SAMPLES)

$(SAMPLES):
	$(MAKE) -C $@
