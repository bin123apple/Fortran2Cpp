module random
  implicit none
  real(8) :: pi = asin(1.0_8)*2

contains

  subroutine init_random_seed()
    integer :: i, n, clock
    integer, dimension(:), allocatable :: seed
    call random_seed(size = n)
    allocate(seed(n))
    call system_clock(count=clock)
    seed = clock + 37 * [(i - 1, i = 1, n)]
    call random_seed(put = seed)
    deallocate(seed)
  end subroutine init_random_seed

  subroutine set_random_seed(seed_offset)
    integer :: i, n, seed_offset
    integer, dimension(:), allocatable :: seed
    call random_seed(size = n)
    allocate(seed(n))
    seed = seed_offset + 37 * [(i - 1, i = 1, n)]
    call random_seed(put = seed)
    deallocate(seed)
  end subroutine set_random_seed

  function rand_uniform() result(ru)
    real(8) :: ru
    call random_number(ru)
  end function rand_uniform

  function rand_int(lo, up) result(ri)
    integer :: ri, lo, up
    real(8) :: rn
    call random_number(rn)
    ri = floor(rn*(up-lo)+0.5)+lo
  end function rand_int

  function rand_vec(n) result(rv)
    integer :: n
    real(8) :: rv(n)
    call random_number(rv)
  end function rand_vec

  function randc(x0, gamma) result(rc)
    real(8) :: rc, x0, gamma
    rc = tan((rand_uniform()-0.5)*pi)*gamma + x0
  end function randc

  function randn(mean, std) result(rn)
    real(8) :: rn, mean, std
    rn = (-2 * log(rand_uniform())) ** 0.5 * cos(2*pi * rand_uniform()) * std + mean
  end function randn

  function randn_vec(n) result(rnv)
    integer :: n, i
    real(8) :: rnv(n)
    do i = 1, n
      rnv(i) = randn(0.0_8, 1.0_8)
    end do
  end function randn_vec

end module random

program test_random
  use random
  implicit none
  real(8) :: uni
  integer :: int
  real(8), allocatable :: vec(:)

  ! Initialize random seed
  call init_random_seed()

  ! Test uniform distribution
  uni = rand_uniform()
  print *, 'Uniform random number:', uni

  ! Test random integer
  int = rand_int(1, 10)
  print *, 'Random integer between 1 and 10:', int

  ! Test random vector
  vec = rand_vec(5)
  print *, 'Random vector:', vec

  ! Feel free to add more tests for other functions like randc, randn, etc.
end program test_random