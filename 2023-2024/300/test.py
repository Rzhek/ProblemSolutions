def max_time_to_first_cell(M, N):
    # Total number of hexagonal cells
    total_cells = M * N - (N // 2)
    
    # Total number of walls
    total_walls = 2 * M * N - M - N
    
    # The maximum time is the total number of walls minus 1
    return total_walls

# Test cases
print(max_time_to_first_cell(2, 1))  # Expected: 11
print(max_time_to_first_cell(3, 3))  # Expected: 32