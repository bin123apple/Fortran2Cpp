PROGRAM GenerateKML
IMPLICIT NONE

! File variable
INTEGER :: iunit
! Filename
CHARACTER(LEN=20) :: filename = 'test.kml'

! Open file
OPEN(UNIT=iunit, FILE=filename, STATUS='replace', ACTION='write')

! Write the header of the KML file
CALL WriteKMLHeader(iunit)

! Write a simple placemark
CALL WritePlacemark(iunit, "Test Placemark", 10.0, 10.0, 1.0)

! End the KML file
CALL WriteKMLEnd(iunit)

! Close the file
CLOSE(iunit)

END PROGRAM GenerateKML

SUBROUTINE WriteKMLHeader(iunit)
INTEGER, INTENT(IN) :: iunit
WRITE(iunit,*) '<?xml version="1.0" encoding="UTF-8"?>'
WRITE(iunit,*) '<kml xmlns="http://www.opengis.net/kml/2.2">'
WRITE(iunit,*) '<Document>'
END SUBROUTINE WriteKMLHeader

SUBROUTINE WritePlacemark(iunit, name, latitude, longitude, altitude)
INTEGER, INTENT(IN) :: iunit
CHARACTER(LEN=*), INTENT(IN) :: name
REAL, INTENT(IN) :: latitude, longitude, altitude
WRITE(iunit,*) '<Placemark>'
WRITE(iunit,*) '<name>', name, '</name>'
WRITE(iunit,*) '<Point>'
WRITE(iunit,*) '<coordinates>', longitude, ',', latitude, ',', altitude, '</coordinates>'
WRITE(iunit,*) '</Point>'
WRITE(iunit,*) '</Placemark>'
END SUBROUTINE WritePlacemark

SUBROUTINE WriteKMLEnd(iunit)
INTEGER, INTENT(IN) :: iunit
WRITE(iunit,*) '</Document>'
WRITE(iunit,*) '</kml>'
END SUBROUTINE WriteKMLEnd