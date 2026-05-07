#!/bin/bash

# RPN single-argument test suite
# Format: ./rpn "5 5 +"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo "========== RPN SINGLE-ARG TEST SUITE =========="

cd /home/muhsin/Desktop/Cpp-Modules/CPP09/ex01 || exit 1

make -s clean
make -s

if [ ! -f ./rpn ]; then
    echo -e "${RED}[ERROR] rpn executable not found${NC}"
    exit 1
fi

run_test() {
    local desc="$1"
    local expr="$2"
    echo -e "\n${YELLOW}${desc}${NC}"
    echo "Command: ./rpn \"$expr\""
    ./rpn "$expr"
}

echo "\n========== VALID EXPRESSIONS =========="
run_test "T1: Basic add (5+5)" "5 5 +"
run_test "T2: Basic sub (9-3)" "9 3 -"
run_test "T3: Basic mul (4*7)" "4 7 *"
run_test "T4: Basic div (8/2)" "8 2 /"
run_test "T5: Mixed ((5*5)+6)-7" "5 5 * 6 + 7 -"
run_test "T6: Mixed (1+2)*(3+4)" "1 2 + 3 4 + *"
run_test "T7: Deep stack" "8 2 / 3 + 4 * 6 -"
run_test "T8: Long chain" "9 1 - 2 * 3 + 4 - 5 * 6 /"

echo "\n========== INVALID EXPRESSIONS =========="
run_test "E1: Invalid char" "5 a +"
run_test "E2: Invalid operator" "5 5 %"
run_test "E3: Missing operand" "5 +"
run_test "E4: Extra operand" "5 5"
run_test "E5: Starts with operator" "+ 5 5"
run_test "E6: Divide by zero" "7 0 /"
run_test "E7: Multi-digit token" "10 2 +"
run_test "E8: Negative token" "-5 2 +"
run_test "E9: Empty string" ""
run_test "E10: Spaces only" "   "

echo "\nDone."
