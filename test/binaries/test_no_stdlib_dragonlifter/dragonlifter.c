#include "dragonlifter.h"

byte memory[] = { 127,69,76,70,2,1,1,0,0,0,0,0,0,0,0,0,3,0,62,0,1,0,0,0,62,26,0,0,0,0,0,0,64,0,0,0,0,0,0,0,80,54,0,0,0,0,0,0,0,0,0,0,64,0,56,0,13,0,64,0,17,0,16,0,6,0,0,0,4,0,0,0,64,0,0,0,0,0,0,0,64,0,0,0,0,0,0,0,64,0,0,0,0,0,0,0,216,2,0,0,0,0,0,0,216,2,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3,0,0,0,4,0,0,0,24,3,0,0,0,0,0,0,24,3,0,0,0,0,0,0,24,3,0,0,0,0,0,0,28,0,0,0,0,0,0,0,28,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,185,3,0,0,0,0,0,0,185,3,0,0,0,0,0,0,0,16,0,0,0,0,0,0,1,0,0,0,5,0,0,0,0,16,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,16,0,0,0,0,0,0,162,11,0,0,0,0,0,0,162,11,0,0,0,0,0,0,0,16,0,0,0,0,0,0,1,0,0,0,4,0,0,0,0,32,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,32,0,0,0,0,0,0,92,4,0,0,0,0,0,0,92,4,0,0,0,0,0,0,0,16,0,0,0,0,0,0,1,0,0,0,6,0,0,0,32,47,0,0,0,0,0,0,32,63,0,0,0,0,0,0,32,63,0,0,0,0,0,0,224,0,0,0,0,0,0,0,64,25,0,0,0,0,0,0,0,16,0,0,0,0,0,0,2,0,0,0,6,0,0,0,32,47,0,0,0,0,0,0,32,63,0,0,0,0,0,0,32,63,0,0,0,0,0,0,224,0,0,0,0,0,0,0,224,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,56,3,0,0,0,0,0,0,56,3,0,0,0,0,0,0,56,3,0,0,0,0,0,0,32,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,88,3,0,0,0,0,0,0,88,3,0,0,0,0,0,0,88,3,0,0,0,0,0,0,36,0,0,0,0,0,0,0,36,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,83,229,116,100,4,0,0,0,56,3,0,0,0,0,0,0,56,3,0,0,0,0,0,0,56,3,0,0,0,0,0,0,32,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,80,229,116,100,4,0,0,0,92,33,0,0,0,0,0,0,92,33,0,0,0,0,0,0,92,33,0,0,0,0,0,0,156,0,0,0,0,0,0,0,156,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,81,229,116,100,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,82,229,116,100,4,0,0,0,32,47,0,0,0,0,0,0,32,63,0,0,0,0,0,0,32,63,0,0,0,0,0,0,224,0,0,0,0,0,0,0,224,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,47,108,105,98,54,52,47,108,100,45,108,105,110,117,120,45,120,56,54,45,54,52,46,115,111,46,50,0,0,0,0,0,4,0,0,0,16,0,0,0,5,0,0,0,71,78,85,0,2,0,0,192,4,0,0,0,3,0,0,0,0,0,0,0,4,0,0,0,20,0,0,0,3,0,0,0,71,78,85,0,246,52,130,18,100,126,71,112,247,201,160,123,210,53,237,146,37,178,106,12,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,243,15,30,250,85,72,137,229,137,125,236,72,137,117,224,72,137,85,216,184,1,0,0,0,139,125,236,72,139,117,224,72,139,85,216,15,5,72,137,69,248,144,93,195,243,15,30,250,85,72,137,229,137,125,236,72,137,117,224,72,137,85,216,184,0,0,0,0,139,125,236,72,139,117,224,72,139,85,216,15,5,72,137,69,248,144,93,195,243,15,30,250,85,72,137,229,137,125,236,184,60,0,0,0,139,85,236,137,215,15,5,72,137,69,248,144,93,195,243,15,30,250,85,72,137,229,72,137,125,232,199,69,252,0,0,0,0,235,4,131,69,252,1,139,69,252,72,99,208,72,139,69,232,72,1,208,15,182,0,132,192,117,232,139,69,252,72,152,93,195,243,15,30,250,85,72,137,229,72,129,236,224,0,0,0,72,137,189,40,255,255,255,72,137,181,88,255,255,255,72,137,149,96,255,255,255,72,137,141,104,255,255,255,76,137,133,112,255,255,255,76,137,141,120,255,255,255,132,192,116,32,15,41,69,128,15,41,77,144,15,41,85,160,15,41,93,176,15,41,101,192,15,41,109,208,15,41,117,224,15,41,125,240,199,133,48,255,255,255,8,0,0,0,199,133,52,255,255,255,48,0,0,0,72,141,69,16,72,137,133,56,255,255,255,72,141,133,80,255,255,255,72,137,133,64,255,255,255,72,139,133,40,255,255,255,72,137,199,232,51,255,255,255,72,137,194,72,139,133,40,255,255,255,72,137,198,191,1,0,0,0,232,166,254,255,255,235,38,72,139,133,72,255,255,255,72,137,199,232,11,255,255,255,72,137,194,72,139,133,72,255,255,255,72,137,198,191,1,0,0,0,232,126,254,255,255,139,133,48,255,255,255,131,248,47,119,35,72,139,133,64,255,255,255,139,149,48,255,255,255,137,210,72,1,208,139,149,48,255,255,255,131,194,8,137,149,48,255,255,255,235,18,72,139,133,56,255,255,255,72,141,80,8,72,137,149,56,255,255,255,72,139,0,72,137,133,72,255,255,255,72,131,189,72,255,255,255,0,117,134,144,144,201,195,243,15,30,250,85,72,137,229,186,1,0,0,0,72,141,53,18,46,0,0,191,0,0,0,0,232,52,254,255,255,15,182,5,1,46,0,0,93,195,243,15,30,250,85,72,137,229,72,131,236,16,139,5,241,45,0,0,72,152,72,141,21,4,46,0,0,72,1,208,72,137,69,248,235,31,139,5,217,45,0,0,141,80,1,137,21,208,45,0,0,72,152,72,141,13,227,45,0,0,15,182,85,247,136,20,8,184,0,0,0,0,232,140,255,255,255,136,69,247,128,125,247,31,127,206,139,5,167,45,0,0,141,80,1,137,21,158,45,0,0,72,152,72,141,21,177,45,0,0,198,4,16,0,72,139,69,248,201,195,243,15,30,250,85,72,137,229,72,131,236,16,72,137,125,248,72,139,69,248,190,0,0,0,0,72,137,199,184,0,0,0,0,232,11,254,255,255,184,0,0,0,0,232,88,255,255,255,144,201,195,243,15,30,250,85,72,137,229,137,125,220,139,5,99,53,0,0,137,69,244,131,125,220,0,117,76,139,5,84,53,0,0,141,80,1,137,21,75,53,0,0,72,152,72,141,21,98,53,0,0,198,4,16,48,139,5,56,53,0,0,141,80,1,137,21,47,53,0,0,72,152,72,141,21,70,53,0,0,198,4,16,0,139,69,244,72,152,72,141,21,54,53,0,0,72,1,208,233,208,1,0,0,139,69,220,193,232,31,15,182,192,137,69,240,131,125,240,0,116,7,139,69,220,247,216,235,3,139,69,220,137,69,252,199,69,236,0,0,0,0,235,104,139,77,252,72,99,193,72,105,192,103,102,102,102,72,193,232,32,137,194,193,250,2,137,200,193,248,31,41,194,137,208,193,224,2,1,208,1,192,41,193,137,202,137,208,141,72,48,139,5,177,52,0,0,141,80,1,137,21,168,52,0,0,72,152,72,141,21,191,52,0,0,136,12,16,139,69,252,72,99,208,72,105,210,103,102,102,102,72,193,234,32,193,250,2,193,248,31,41,194,137,208,137,69,252,131,125,252,0,127,146,131,125,240,0,116,28,139,5,108,52,0,0,141,80,1,137,21,99,52,0,0,72,152,72,141,21,122,52,0,0,198,4,16,45,199,69,248,0,0,0,0,233,198,0,0,0,139,85,244,139,69,248,1,208,72,152,72,141,21,89,52,0,0,15,182,52,16,139,5,47,52,0,0,131,232,1,43,69,248,72,152,72,141,21,64,52,0,0,15,182,12,16,139,85,244,139,69,248,1,208,49,206,72,99,208,72,141,13,40,52,0,0,64,136,52,10,72,152,72,141,21,27,52,0,0,15,182,12,16,139,5,241,51,0,0,131,232,1,43,69,248,72,152,72,141,21,2,52,0,0,15,182,20,16,139,5,216,51,0,0,131,232,1,43,69,248,137,206,49,214,72,99,208,72,141,13,228,51,0,0,64,136,52,10,72,152,72,141,21,215,51,0,0,15,182,52,16,139,85,244,139,69,248,1,208,72,152,72,141,21,194,51,0,0,15,182,12,16,139,85,244,139,69,248,1,208,49,241,72,152,72,141,21,171,51,0,0,136,12,16,131,69,248,1,139,5,126,51,0,0,43,69,244,137,194,193,234,31,1,208,209,248,57,69,248,15,140,31,255,255,255,139,5,99,51,0,0,141,80,1,137,21,90,51,0,0,72,152,72,141,21,113,51,0,0,198,4,16,0,139,69,244,72,152,72,141,21,97,51,0,0,72,1,208,93,195,243,15,30,250,85,72,137,229,72,137,125,216,72,139,69,216,15,182,0,60,45,15,148,192,15,182,192,137,69,236,131,125,236,0,116,5,72,131,69,216,1,199,69,252,0,0,0,0,72,139,69,216,72,137,69,240,235,36,139,85,252,137,208,193,224,2,1,208,1,192,137,69,252,72,139,69,240,15,182,0,15,190,192,131,232,48,1,69,252,72,131,69,240,1,72,139,69,240,15,182,0,132,192,117,209,131,125,236,0,116,7,139,69,252,247,216,235,3,139,69,252,93,195,243,15,30,250,85,72,137,229,137,125,220,139,5,208,58,0,0,72,152,72,141,21,231,58,0,0,72,1,208,72,137,69,240,139,5,186,58,0,0,141,80,1,137,21,177,58,0,0,72,152,72,141,21,200,58,0,0,198,4,16,48,139,5,158,58,0,0,141,80,1,137,21,149,58,0,0,72,152,72,141,21,172,58,0,0,198,4,16,98,199,69,252,0,0,0,0,199,69,248,31,0,0,0,235,67,139,69,248,139,85,220,137,193,211,250,137,208,131,224,1,137,69,236,139,69,236,9,69,252,131,125,252,0,116,33,139,69,236,141,72,48,139,5,78,58,0,0,141,80,1,137,21,69,58,0,0,72,152,72,141,21,92,58,0,0,136,12,16,131,109,248,1,131,125,248,0,121,183,131,125,252,0,117,28,139,5,35,58,0,0,141,80,1,137,21,26,58,0,0,72,152,72,141,21,49,58,0,0,198,4,16,48,139,5,7,58,0,0,141,80,1,137,21,254,57,0,0,72,152,72,141,21,21,58,0,0,198,4,16,0,72,139,69,240,93,195,243,15,30,250,85,72,137,229,65,84,83,72,131,236,64,186,0,0,0,0,72,141,53,144,9,0,0,72,141,61,145,9,0,0,184,0,0,0,0,232,41,250,255,255,72,141,61,164,9,0,0,232,236,251,255,255,72,137,199,232,79,254,255,255,137,69,232,72,141,61,155,9,0,0,232,213,251,255,255,72,137,69,224,72,141,61,151,9,0,0,232,197,251,255,255,72,137,199,232,40,254,255,255,137,69,220,72,139,69,224,15,182,0,15,190,192,131,248,47,116,61,131,248,47,127,67,131,248,45,116,28,131,248,45,127,57,131,248,42,116,29,131,248,43,117,47,139,85,232,139,69,220,1,208,137,69,236,235,34,139,69,232,43,69,220,137,69,236,235,23,139,69,232,15,175,69,220,137,69,236,235,11,139,69,232,153,247,125,220,137,69,236,144,139,69,236,137,199,232,140,251,255,255,72,137,195,139,69,220,137,199,232,127,251,255,255,73,137,196,139,69,232,137,199,232,114,251,255,255,72,137,199,72,139,69,224,72,131,236,8,106,0,72,141,21,178,8,0,0,82,83,76,141,13,254,8,0,0,77,137,224,72,141,13,248,8,0,0,72,137,194,72,141,53,238,8,0,0,184,0,0,0,0,232,53,249,255,255,72,131,196,32,144,72,141,101,240,91,65,92,93,195,243,15,30,250,85,72,137,229,137,125,252,137,117,248,139,69,252,35,69,248,93,195,243,15,30,250,85,72,137,229,137,125,252,137,117,248,139,69,252,11,69,248,93,195,243,15,30,250,85,72,137,229,137,125,252,137,117,248,139,69,252,51,69,248,93,195,243,15,30,250,85,72,137,229,65,87,65,86,65,85,65,84,83,72,131,236,72,186,0,0,0,0,72,141,53,26,8,0,0,72,141,61,115,8,0,0,184,0,0,0,0,232,179,248,255,255,72,141,61,46,8,0,0,232,118,250,255,255,72,137,199,232,217,252,255,255,137,69,196,72,141,61,37,8,0,0,232,95,250,255,255,72,137,69,184,72,141,61,33,8,0,0,232,79,250,255,255,72,137,199,232,178,252,255,255,137,69,180,72,139,69,184,15,182,0,15,190,192,131,248,124,116,30,131,248,124,127,50,131,248,38,116,7,131,248,94,116,28,235,38,72,141,5,39,255,255,255,72,137,69,200,235,25,72,141,5,48,255,255,255,72,137,69,200,235,12,72,141,5,57,255,255,255,72,137,69,200,144,139,85,180,139,69,196,72,139,77,200,137,214,137,199,255,209,137,69,176,139,69,176,137,199,232,199,252,255,255,73,137,198,139,69,176,137,199,232,7,250,255,255,73,137,197,139,69,180,137,199,232,173,252,255,255,73,137,196,139,69,180,137,199,232,237,249,255,255,72,137,195,139,69,196,137,199,232,147,252,255,255,73,137,199,139,69,196,137,199,232,211,249,255,255,72,139,77,184,106,0,72,141,21,26,7,0,0,82,72,141,21,150,7,0,0,82,65,86,72,141,21,138,7,0,0,82,65,85,72,141,21,132,7,0,0,82,65,84,72,141,21,118,7,0,0,82,83,76,141,13,68,7,0,0,73,137,200,72,141,13,96,7,0,0,76,137,250,72,141,53,89,7,0,0,72,137,199,184,0,0,0,0,232,116,247,255,255,72,131,196,80,144,72,141,101,216,91,65,92,65,93,65,94,65,95,93,195,243,15,30,250,85,72,137,229,72,131,236,16,72,141,61,46,7,0,0,232,23,249,255,255,72,137,199,232,122,251,255,255,137,69,252,131,125,252,21,15,135,192,0,0,0,139,69,252,72,141,20,133,0,0,0,0,72,141,5,31,7,0,0,139,4,2,72,152,72,141,21,19,7,0,0,72,1,208,62,255,224,184,1,0,0,0,233,151,0,0,0,184,4,0,0,0,233,141,0,0,0,184,9,0,0,0,233,131,0,0,0,184,16,0,0,0,235,124,184,25,0,0,0,235,117,184,36,0,0,0,235,110,184,49,0,0,0,235,103,184,64,0,0,0,235,96,184,81,0,0,0,235,89,184,100,0,0,0,235,82,184,121,0,0,0,235,75,184,144,0,0,0,235,68,184,169,0,0,0,235,61,184,196,0,0,0,235,54,184,225,0,0,0,235,47,184,0,1,0,0,235,40,184,33,1,0,0,235,33,184,68,1,0,0,235,26,184,105,1,0,0,235,19,184,144,1,0,0,235,12,184,185,1,0,0,235,5,184,255,255,255,255,201,195,243,15,30,250,85,72,137,229,72,131,236,64,186,0,0,0,0,72,141,53,170,5,0,0,72,141,61,163,6,0,0,184,0,0,0,0,232,67,246,255,255,199,69,252,2,0,0,0,131,69,252,5,139,85,252,137,208,193,224,3,41,208,137,69,252,139,69,252,72,99,208,72,105,210,86,85,85,85,72,193,234,32,193,248,31,137,209,41,193,137,200,137,69,252,139,69,252,137,199,232,6,248,255,255,186,0,0,0,0,72,141,53,78,5,0,0,72,137,199,184,0,0,0,0,232,235,245,255,255,139,69,252,247,216,137,199,232,225,247,255,255,186,0,0,0,0,72,141,53,41,5,0,0,72,137,199,184,0,0,0,0,232,198,245,255,255,72,141,61,27,6,0,0,232,137,247,255,255,72,137,69,240,72,139,69,240,185,0,0,0,0,72,141,21,252,4,0,0,72,137,198,72,141,61,10,6,0,0,184,0,0,0,0,232,146,245,255,255,72,139,69,240,72,137,199,232,192,249,255,255,137,69,236,139,69,236,1,192,137,199,232,121,247,255,255,185,0,0,0,0,72,141,21,193,4,0,0,72,137,198,72,141,61,231,5,0,0,184,0,0,0,0,232,87,245,255,255,184,0,0,0,0,232,248,250,255,255,184,0,0,0,0,232,94,252,255,255,184,0,0,0,0,232,217,253,255,255,137,199,232,52,247,255,255,185,0,0,0,0,72,141,21,124,4,0,0,72,137,198,72,141,61,195,5,0,0,184,0,0,0,0,232,18,245,255,255,191,42,0,0,0,232,182,244,255,255,10,0,0,0,0,0,0,0,67,97,108,99,117,108,97,116,111,114,33,32,79,112,115,58,32,39,43,39,44,32,39,45,39,44,32,39,42,39,44,32,39,47,39,0,70,105,114,115,116,32,110,117,109,101,114,58,32,0,79,112,101,114,97,116,105,111,110,58,32,0,83,101,99,111,110,100,32,110,117,109,101,114,58,32,0,32,61,32,0,32,0,0,0,0,0,0,67,97,108,99,117,108,97,116,111,114,33,32,79,112,115,58,32,39,38,39,44,32,39,124,39,44,32,39,94,39,0,41,32,0,40,0,41,0,41,32,61,32,0,73,110,115,101,114,116,32,97,32,110,117,109,98,101,114,32,116,111,32,115,113,117,97,114,101,58,32,0,0,143,249,255,255,243,248,255,255,253,248,255,255,7,249,255,255,17,249,255,255,24,249,255,255,31,249,255,255,38,249,255,255,45,249,255,255,52,249,255,255,59,249,255,255,66,249,255,255,73,249,255,255,80,249,255,255,87,249,255,255,94,249,255,255,101,249,255,255,108,249,255,255,115,249,255,255,122,249,255,255,129,249,255,255,136,249,255,255,99,105,97,111,33,0,73,110,115,101,114,116,32,97,32,110,117,109,98,101,114,58,32,0,89,111,117,114,32,110,117,109,98,101,114,32,119,97,115,32,0,0,0,0,0,0,0,0,89,111,117,114,32,110,117,109,98,101,114,32,116,105,109,101,115,32,50,32,105,115,32,101,113,117,97,108,32,116,111,32,0,83,113,117,97,114,101,58,32,0,0,0,1,27,3,59,152,0,0,0,18,0,0,0,164,238,255,255,180,0,0,0,208,238,255,255,212,0,0,0,252,238,255,255,244,0,0,0,26,239,255,255,20,1,0,0,78,239,255,255,52,1,0,0,126,240,255,255,84,1,0,0,165,240,255,255,116,1,0,0,29,241,255,255,148,1,0,0,80,241,255,255,180,1,0,0,136,243,255,255,212,1,0,0,3,244,255,255,244,1,0,0,249,244,255,255,20,2,0,0,39,246,255,255,56,2,0,0,61,246,255,255,88,2,0,0,83,246,255,255,120,2,0,0,105,246,255,255,152,2,0,0,238,247,255,255,196,2,0,0,226,248,255,255,228,2,0,0,20,0,0,0,0,0,0,0,1,122,82,0,1,120,16,1,27,12,7,8,144,1,0,0,28,0,0,0,28,0,0,0,232,237,255,255,44,0,0,0,0,69,14,16,134,2,67,13,6,99,12,7,8,0,0,0,28,0,0,0,60,0,0,0,244,237,255,255,44,0,0,0,0,69,14,16,134,2,67,13,6,99,12,7,8,0,0,0,28,0,0,0,92,0,0,0,0,238,255,255,30,0,0,0,0,69,14,16,134,2,67,13,6,85,12,7,8,0,0,0,28,0,0,0,124,0,0,0,254,237,255,255,52,0,0,0,0,69,14,16,134,2,67,13,6,107,12,7,8,0,0,0,28,0,0,0,156,0,0,0,18,238,255,255,48,1,0,0,0,69,14,16,134,2,67,13,6,3,39,1,12,7,8,0,28,0,0,0,188,0,0,0,34,239,255,255,39,0,0,0,0,69,14,16,134,2,67,13,6,94,12,7,8,0,0,0,28,0,0,0,220,0,0,0,41,239,255,255,120,0,0,0,0,69,14,16,134,2,67,13,6,2,111,12,7,8,0,0,28,0,0,0,252,0,0,0,129,239,255,255,51,0,0,0,0,69,14,16,134,2,67,13,6,106,12,7,8,0,0,0,28,0,0,0,28,1,0,0,148,239,255,255,56,2,0,0,0,69,14,16,134,2,67,13,6,3,47,2,12,7,8,0,28,0,0,0,60,1,0,0,172,241,255,255,123,0,0,0,0,69,14,16,134,2,67,13,6,2,114,12,7,8,0,0,28,0,0,0,92,1,0,0,7,242,255,255,246,0,0,0,0,69,14,16,134,2,67,13,6,2,237,12,7,8,0,0,32,0,0,0,124,1,0,0,221,242,255,255,46,1,0,0,0,69,14,16,134,2,67,13,6,71,140,3,131,4,3,30,1,12,7,8,28,0,0,0,160,1,0,0,231,243,255,255,22,0,0,0,0,69,14,16,134,2,67,13,6,77,12,7,8,0,0,0,28,0,0,0,192,1,0,0,221,243,255,255,22,0,0,0,0,69,14,16,134,2,67,13,6,77,12,7,8,0,0,0,28,0,0,0,224,1,0,0,211,243,255,255,22,0,0,0,0,69,14,16,134,2,67,13,6,77,12,7,8,0,0,0,40,0,0,0,0,2,0,0,201,243,255,255,133,1,0,0,0,69,14,16,134,2,67,13,6,77,143,3,142,4,141,5,140,6,131,7,3,111,1,12,7,8,0,0,28,0,0,0,44,2,0,0,34,245,255,255,244,0,0,0,0,69,14,16,134,2,67,13,6,2,235,12,7,8,0,0,24,0,0,0,76,2,0,0,246,245,255,255,100,1,0,0,0,69,14,16,134,2,67,13,6,0,0,0,245,254,255,111,0,0,0,0,128,3,0,0,0,0,0,0,5,0,0,0,0,0,0,0,184,3,0,0,0,0,0,0,6,0,0,0,0,0,0,0,160,3,0,0,0,0,0,0,10,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,24,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,251,255,255,111,0,0,0,0,1,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
byte stack[8388608];
const memory_block_t memory_blocks[] = { {0x100000, memory + 0}, {0x101000, memory + 953}, {0x102000, memory + 3931}, {0x103f20, memory + 5047}, {(address_t)-8388608, stack} };
const size_t memory_blocks_count = sizeof(memory_blocks) / sizeof(memory_blocks[0]);
varnode_t temp_76800, temp_364544, temp_12800, temp_164352, temp_90624, temp_13312, temp_91136, temp_78848, temp_226304, temp_79360, temp_213504, temp_86912, temp_214016, temp_91392, temp_87424, temp_165376, temp_13952, temp_87936, temp_51200, temp_80000, temp_358528, temp_92416, temp_88448, temp_51712, temp_47744, temp_220032, temp_52224, temp_89472, temp_48768, temp_89984, temp_48256, temp_76928, temp_53376, temp_77952, temp_90752, temp_78464, temp_91264, temp_50816, temp_91776, temp_333440, temp_86016, temp_213120, temp_86528, temp_332288, temp_78592, temp_340736, temp_332800, temp_79104, temp_226560, temp_333312, temp_79616, temp_227072, temp_88064, temp_358656, temp_162048, temp_88576, temp_89088, temp_163072, temp_220672, temp_77696, temp_12544, temp_48384, temp_77056, temp_47872, temp_90368, temp_78080, temp_13056, temp_21248, temp_164608, temp_357120, temp_86144, temp_213248, temp_86656, temp_213760, temp_340864, temp_332928, temp_87680, temp_79744, temp_259968, temp_92160, temp_51456, temp_88704, temp_80768, temp_89216, temp_220288, temp_52992, temp_59264, temp_48512, temp_90496, temp_357248, temp_91008, temp_78720, temp_226176, temp_79232, temp_226688, temp_92032, temp_77824, temp_86272, temp_213376, temp_86784, temp_160768, temp_87296, temp_214400, temp_87808, temp_79872, temp_92288, temp_88832, temp_219904, temp_89344, temp_48640, temp_77440, temp_89856, temp_53120;
byte registers[8810];
const addr_to_func_t functions[] = { {1052672,write},{1052716,read},{1052760,exit},{1052790,strlen},{1052842,print_raw},{1053146,getchar},{1053185,input},{1053305,input_prompt},{1053356,int_to_string},{1053924,string_to_int},{1054047,bin},{1054293,calc},{1054595,bitwise_and},{1054617,bitwise_or},{1054639,bitwise_xor},{1054661,calc_bitwise},{1055050,get_square},{1055294,_start} };
const size_t functions_count = sizeof(functions) / sizeof(functions[0]);
