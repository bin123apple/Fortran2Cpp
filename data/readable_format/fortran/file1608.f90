program atomic_example
implicit none
integer :: a
logical :: c
integer(8) :: b
logical :: d

! Mimicking atomic_define and atomic_ref behavior without atomic operations
a = 7
b = a
if (b /= 7) then
    print *, "Mismatch in integer values, stopping."
    stop 1
endif

c = .false.
d = c
if (d .neqv. .false.) then
    print *, "Expected false, stopping."
    stop 2
endif

c = .true.
d = c
if (d .neqv. .true.) then
    print *, "Expected true, stopping."
    stop 3
endif

print *, "All tests passed."

end program atomic_example