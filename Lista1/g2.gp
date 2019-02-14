set terminal eps
set output "img2.eps"
set xrange[-1:11]
set grid
set xtics 1
plot "./coord2.txt" with lp, x * cos(x) 
quit
