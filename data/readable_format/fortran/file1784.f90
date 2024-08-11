program main
  implicit none
  integer :: n
  real :: s
  n = 3
  block
    block
      block
        block
          block
            real, dimension(n) :: a
            a = 3.
            s = sum(a)
          end block
        end block
      end block
    end block
  end block
  if (s /= 9) call abort
  ! Simple test
  if (s == 9) then
    print *, "Test passed."
  else
    print *, "Test failed."
    stop 1
  end if
end program main