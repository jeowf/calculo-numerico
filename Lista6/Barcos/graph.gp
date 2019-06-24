set terminal png
set output "img2.png"
set grid
set xrange[8.4:10]
plot "./barcos.txt" title "Pontos", 3.23012*x*x - 64.1692*x + 322.072
quit
