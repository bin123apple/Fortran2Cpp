! stream_test.f90
program stream_test
implicit none
integer :: ios
open(10, status='scratch', access='stream')
write (10, iostat=ios) "This is a test"
if (ios /= 0) then
    print *, "Error occurred during file write."
    stop
endif
end program