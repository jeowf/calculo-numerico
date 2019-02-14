set terminal eps
set output "img1.eps"
set xrange[-1.5:2.5]
set grid
set xzeroaxis
set xtics 0.5
plot x*x*x - 2 * x * x - x + 2 title "função cúbica", -2*x + 2 title "reta tangente em x = 1", "./coord1.txt", 2.1, -0.63
quit
