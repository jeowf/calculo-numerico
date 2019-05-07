set terminal png
set output "img2.png"
set xrange[-1:8]
set grid
set xtics 1
plot "./coord.txt" with lp title "Interpolação Linear", 1 + x - (0.75)*x**2 + (0.75)*2*x + (0.21)*x**3 - (0.21)*6*x**2 + (0.21)*8 * x title "Interpolação de Newton", "./coord.txt" title "Pontos"
quit
