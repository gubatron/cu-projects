#!/bin/bash

build_task() {
    cd $1
    ./build.sh
    cd ..
}

build_task doubly_linked_list
build_task ht_chaining
build_task ht_linear_probing
build_task ht_quadratic_probing
build_task std_map


