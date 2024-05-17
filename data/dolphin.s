.data

.int (end-start+15) & ~15
.int dolphin_end-dolphin
.int disc_end-disc
.int 0

start:

dolphin:
.incbin "data/dolphin.dll"
dolphin_end:

disc:
.incbin "data/disc.rvz"
disc_end:

end:
