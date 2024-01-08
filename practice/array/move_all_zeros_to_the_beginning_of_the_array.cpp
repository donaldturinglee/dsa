void MoveZerosToLeft(vector<int> &nums) {
    int length = nums.size();
    if (length < 1) return;
    int read_pointer = length - 1;
    int write_pointer = length - 1;

    while (read_pointer >= 0)
    {
        if (nums.at(read_pointer) != 0)
        {
            nums.at(write_pointer) = nums.at(read_pointer);
            --write_pointer;
        }
        --read_pointer;
    }

    while (write_pointer >= 0)
    {
        nums.at(write_pointer) = 0;
        --write_pointer;
    }

    return;
}