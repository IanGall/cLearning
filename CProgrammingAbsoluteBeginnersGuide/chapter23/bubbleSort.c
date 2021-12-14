void bubbleSortInt(int inner, int outer, int didSwap, int temp, int *nums);

void bubbleSortIntWithFloat(int inner, int outer, int didSwap, int temp, int *nums, float *extra);

void bubbleSortInt(int inner, int outer, int didSwap, int temp, int *nums) {
    for (outer = 0; outer < 9; ++outer) {
        didSwap = 0; //Becomes 1(true) if list is not yet ordered
        for (inner = outer; inner < 10; ++inner) {
            if (nums[inner] < nums[outer]) {
                temp = nums[inner];
                nums[inner] = nums[outer];
                nums[outer] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
}

void bubbleSortIntWithFloat(int inner, int outer, int didSwap, int temp, int *nums, float *extra) {
    float tempF;
    for (outer = 0; outer < 9; ++outer) {
        didSwap = 0; //Becomes 1(true) if list is not yet ordered
        for (inner = outer; inner < 10; ++inner) {
            if (nums[inner] < nums[outer]) {
                temp = nums[inner];
                nums[inner] = nums[outer];
                nums[outer] = temp;

                tempF = extra[inner];
                extra[inner] = extra[outer];
                extra[outer] = tempF;

                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
}

