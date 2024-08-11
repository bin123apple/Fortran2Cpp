program test_unpackpfx
  implicit none

  character(len=12) :: call1
  integer :: ng

  ! Test case 1
  call1 = 'CALLSIGN'
  ng = 12345
  call unpackpfx(ng, call1)
  print *, 'Test 1:', call1
  
  ! Test case 2
  call1 = 'TEST    '
  ng = 60010
  call unpackpfx(ng, call1)
  print *, 'Test 2:', call1
  
  ! Test case 3
  call1 = 'EXAMPLE '
  ng = 70000
  call unpackpfx(ng, call1)
  print *, 'Test 3:', call1

contains

  subroutine unpackpfx(ng,call1)
    implicit none
    integer, intent(in) :: ng
    character(len=12), intent(inout) :: call1
    character(len=3) :: pfx
    integer :: n, i, nc, nc1, nc2, i1
    pfx = '   ' ! Initialize pfx with spaces
    
    if (ng < 60000) then
       n = ng
       do i = 3, 1, -1
          nc = mod(n, 37)
          if (nc >= 0 .and. nc <= 9) then
             pfx(i:i) = char(iachar('0') + nc)
          else if (nc >= 10 .and. nc <= 35) then
             pfx(i:i) = char(iachar('A') + nc - 10)
          else
             pfx(i:i) = ' '
          end if
          n = n / 37
       end do
       call1 = trim(adjustl(pfx)) // '/' // trim(adjustl(call1))
    else
       i1 = index(call1, ' ')
       nc = ng - 60000
       if (nc >= 0 .and. nc <= 9) then
          call1 = call1(1:i1-1) // '/' // char(iachar('0') + nc)
       else if (nc >= 10 .and. nc <= 35) then
          call1 = call1(1:i1-1) // '/' // char(iachar('A') + nc - 10)
       else if (nc >= 36 .and. nc <= 125) then
          nc1 = (nc - 26) / 10
          nc2 = mod(nc - 26, 10)
          call1 = call1(1:i1-1) // '/' // char(iachar('0') + nc1) // char(iachar('0') + nc2)
       end if
    end if
  end subroutine unpackpfx

end program test_unpackpfx