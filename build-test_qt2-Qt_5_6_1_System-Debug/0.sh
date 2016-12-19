perf record --call-graph dwarf -- ./test_qt2
perf script -s callgrind.py report > perf.callgrind
kcachegrind ./perf.callgrind
