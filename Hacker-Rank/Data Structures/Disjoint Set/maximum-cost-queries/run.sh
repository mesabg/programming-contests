function compile {
    g++ -o $1 $1.cpp -std=c++0x
}

function test {
    time ./$1 < cases/input/$2.in
}

compile Solution
test Solution case0