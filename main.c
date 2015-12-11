#include "FaNES.h"
#include "imageRLE.h"
#include "bars.h"

const uchar paletteBars[16] = {
    0x0F, 0x00, 0x10, 0x30,
    0x01, 0x11, 0x21, 0x31,
    0x06, 0x16, 0x26, 0x36,
    0x0A, 0x1A, 0x2A, 0x3A
};

const uchar paletteImage[16] = {
    0x05, 0x30, 0x30, 0x30,
    0x05, 0x30, 0x30, 0x30,
    0x05, 0x30, 0x30, 0x30,
    0x05, 0x30, 0x30, 0x30
};

static uchar image;

void main(void) {
    setPaletteBackground(paletteBars);
	unpackNametableRLE(bars, NAMETABLE_A);
	onGraphics();
	while(TRUE) {
        uchar pad = padPush(PAD_PORT_PLAYER_1);
        if (pad) {
            offGraphics();
            if (image) {
                setPaletteBackground(paletteBars);
                unpackNametableRLE(bars, NAMETABLE_A);
            } else {
                setPaletteBackground(paletteImage);
                unpackNametableRLE(imageRLE, NAMETABLE_A);
            }
            onGraphics();
            image = !image;
        }
        waitFrame();
    }
}
