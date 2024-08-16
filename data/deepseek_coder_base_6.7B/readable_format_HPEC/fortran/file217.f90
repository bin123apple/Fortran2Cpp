subroutine print_array(output)
implicit none

DATA_TYPE :: output
write(0, DATA_PRINTF_MODIFIER) output
write(0, *)
end subroutine
