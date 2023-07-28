//
// Created by lishuainan on 2023/7/28.
//
#include "order.h"
#include "info.h"
#include <stdio.h>
#include <string.h>

static const char* file_path="src/data/order.txt";
static const char* header="|ID         |Good       |Price      |Date       |Seller     |Buyer      |";
static const char* divide="+-----------+-----------+-----------+-----------+-----------+-----------+";

void pull