set terminal png
set output "img1.png"
set grid
plot "./in.txt" title "Pontos" lw 1, 1.625 -0.5*cos(2*x) + 2.5732*cos(x) - 1.2803*sin(x) title "S2(x)" lw 2, 1.625 + 0.75*cos(4*x) + 2.5732*cos(x) - 1.2803*sin(x) - 0.5*cos(2*x) + 0.75 * sin(2*x) + 2.9268 * cos(3*x) + 0.2197*sin(3*x) title "S4(x)" lw 2, 1.625 + 3.25*cos(8*x) + 2.5732*cos(x) - 1.2803*sin(x) - 0.5*cos(2*x) + 0.75 * sin(2*x) + 2.9268 * cos(3*x) + 0.2197*sin(3*x) + 0.75 * cos(4*x) + 2.9268*cos(5*x) - 0.2197*sin(5*x) - 0.5 * cos(6*x) -0.75*sin(6*x) + 2.5732*cos(7*x) + 1.2803*sin(7*x) title "S8(x)" lw 2
quit
