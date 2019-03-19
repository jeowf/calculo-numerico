set terminal eps
set output "img2.eps"
set xrange[-6:6]
set grid
set xtics 1
plot "./coord2.txt" with lp title "Aproximação", x * cos(x) + 1 
quit
