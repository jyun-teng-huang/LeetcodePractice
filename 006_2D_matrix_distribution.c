int matrix2DWeightDistribution(int rowSize, int colSize, int** nums){
    int* presumRow = (int*)malloc(sizeof(int)*rowSize);
    int* presumCol = (int*)malloc(sizeof(int)*colSize);
    int* numsRow = (int*)malloc(sizeof(int)*rowSize);
    int* numsCol = (int*)malloc(sizeof(int)*colSize);

    //calculate 1D-row/col-matrix    
    for(int i=0; i<rowSize;i++){
        for(int j=0; j<colSize;j++){
            numsRow[i] = numsRow[i] + nums[i][j];
            numsCol[j] = numsCol[j] + nums[i][j];
        }
    }
    //calculate presum
    for(int i=0; i<rowSize;i++){
        if(i==0){
            presumRow[i] = numsRow[i];
        } else {
            presumRow[i] = numsRow[i] + presumRow[i-1];
        }
    }
    for(int i=0; i<colSize;i++){
        if(i==0){
            presumCol[i] = numsCol[i];
        } else {
            presumCol[i] = numsCol[i] + presumCol[i-1];
        }
    }
    int returnRow = presumRow[rowSize-1];
    int returnCol = presumCol[colSize-1];
    int minDifference;
    int weightDifferent;
    //divide the array into two parts to minimize the difference between their sums.
    for(int i=0; i<rowSize; i++){
        weightDifferent = abs(presumRow[rowSize-1] - presumRow[i]) - presumRow[i];
        if(returnRow > weightDifferent){
            returnRow = weightDifferent;
        } else {
            returnRow = returnRow;
        }
    }
    for(int i=0; i<colSize; i++){
        weightDifferent = abs(presumCol[colSize-1] - presumCol[i]) - presumCol[i];
        if(returnCol > weightDifferent){
            returnCol = weightDifferent;
        } else {
            returnCol = returnCol;
        }
    }
    if(returnCol>returnRow){
        minDifference = returnRow;
    }else{
        minDifference = returnCol;
    }
    return minDifference;        
}