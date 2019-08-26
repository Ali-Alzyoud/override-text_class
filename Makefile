CC?=gcc
EDJE_CC?=edje_cc
CFLAGS?=
LIBS?=
LDFLAGS?=
CFLAGS+=`pkg-config --cflags elementary edje evas`
LIBS+=`pkg-config --libs elementary edje evas`

all: app source.edj

app: source.c
	$(CC) source.c $(CFLAGS) $(LDFLAGS) $(LIBS) -o app

source.edj: source.edc
	$(EDJE_CC) -beta source.edc

clean:
	rm source.edj app

