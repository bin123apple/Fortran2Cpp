program test_write_latlong
      implicit none

      double precision lat(2), longitude(2)
      integer :: i
      double precision, dimension(4) :: readData
      open(unit=20, file='latlong.dat', status='old')

      lat(1) = 35.6895
      lat(2) = 40.7128
      longitude(1) = 139.6917
      longitude(2) = -74.0060

      call write_latlong_data(lat, longitude)

      do i = 1, 4
         read(20,*) readData(i)
      end do

      close(20)

      print *, "Read values are: ", readData
      print *, "Expected values are: ", lat(1), lat(2), longitude(1), longitude(2)

end program test_write_latlong

subroutine write_latlong_data(lat, longitude)
      implicit none

      double precision lat(2), longitude(2)

      open(10,file='latlong.dat')
      write(10,100) lat(1),lat(2),longitude(1),longitude(2)
      close(10)

  100 format(4E24.16)

end subroutine write_latlong_data