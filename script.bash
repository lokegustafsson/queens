SMALL=8
MEDIUM=8
LARGE=8
GREEDYS=100
GREEDYM=1000
GREEDYL=3000

./run.out tests/1_queens.in results/1_queens.out $SMALL $GREEDYS
./run.out tests/2_queens.in results/2_queens.out $SMALL $GREEDYS
./run.out tests/3_queens.in results/3_queens.out $SMALL $GREEDYS
./run.out tests/4_queens.in results/4_queens.out $SMALL $GREEDYS
./run.out tests/5_queens.in results/5_queens.out $MEDIUM $GREEDYS
./run.out tests/6_queens.in results/6_queens.out $MEDIUM $GREEDYS
./run.out tests/7_queens.in results/7_queens.out $MEDIUM $GREEDYM
./run.out tests/8_queens.in results/8_queens.out $MEDIUM $GREEDYM
./run.out tests/9_queens.in results/9_queens.out $MEDIUM $GREEDYM
./run.out tests/10_queens.in results/10_queens.out $MEDIUM $GREEDYM
./run.out tests/11_queens.in results/11_queens.out $MEDIUM $GREEDYM
./run.out tests/12_queens.in results/12_queens.out $MEDIUM $GREEDYM
./run.out tests/13_queens.in results/13_queens.out $MEDIUM $GREEDYM
./run.out tests/14_queens.in results/14_queens.out $MEDIUM $GREEDYM
./run.out tests/15_queens.in results/15_queens.out $LARGE $GREEDYM
./run.out tests/16_queens.in results/16_queens.out $LARGE $GREEDYM
./run.out tests/17_queens.in results/17_queens.out $LARGE $GREEDYM
./run.out tests/18_queens.in results/18_queens.out $LARGE $GREEDYM
./run.out tests/19_queens.in results/19_queens.out $LARGE $GREEDYL
./run.out tests/20_queens.in results/20_queens.out $LARGE $GREEDYL
./score.out
