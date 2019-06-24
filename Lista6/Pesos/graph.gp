set terminal png
set output "img2.png"
set grid
set xrange[1.5:2.05]
set xtics 0.05
plot "./pesos.txt" title "Pontos" lw 1, 70.4268*x - 60.2291 title "Aproximação" lw 2
quit
