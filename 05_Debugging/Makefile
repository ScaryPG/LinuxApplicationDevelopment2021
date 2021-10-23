range: range.c
	gcc range.c -o range -O0 -g

test: range
	sudo gdb -q -x gdb_commands_1.py > /dev/null 2>&1
	cmp gt_1.txt test_1.txt

	sudo gdb -q -x gdb_commands_2.py > /dev/null 2>&1
	cmp gt_2.txt test_2.txt

clean:
	rm -f range
	rm -f test_1.txt
	rm -f test_2.txt
