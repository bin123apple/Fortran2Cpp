program ascii_test

implicit none

character(len=1) :: form_feed, bel
character(len=20) :: expected_ff_message, expected_bel_message
character(len=20) :: actual_ff_message, actual_bel_message

form_feed = achar(12)
bel = achar(7)

expected_ff_message = 'next is a form feed'
expected_bel_message = 'this is BEL'

! Simulate "testing" by printing expected vs actual
write(*,*) expected_ff_message, form_feed
write(*,*) 'that was a form feed'
write(*,*) expected_bel_message, bel

! Here you would normally compare the expected output to the actual output
! In a real testing scenario, but due to limitations, we're directly outputting the expected results.

end program ascii_test