Program simple_file_io
    Implicit None

    Integer :: i
    Integer, Dimension(10) :: data
    Integer :: readData(10)
    
    ! Initialize some data to write
    Do i = 1, 10
        data(i) = i
    End Do

    ! Write data to a file
    Call write_data_to_file('example.dat', data)

    ! Read data from the file
    Call read_data_from_file('example.dat', readData)

    ! Print the read data
    Print *, "Data read from file:", readData

Contains

    Subroutine write_data_to_file(filename, data)
        Character(len=*), Intent(in) :: filename
        Integer, Dimension(:), Intent(in) :: data
        Integer :: i

        Open(unit=10, file=filename, status='replace', action='write')
        Do i = 1, Size(data)
            Write(10, *) data(i)
        End Do
        Close(10)
    End Subroutine write_data_to_file

    Subroutine read_data_from_file(filename, data)
        Character(len=*), Intent(in) :: filename
        Integer, Dimension(:), Intent(out) :: data
        Integer :: i

        Open(unit=10, file=filename, status='old', action='read')
        Do i = 1, Size(data)
            Read(10, *) data(i)
        End Do
        Close(10)
    End Subroutine read_data_from_file

End Program simple_file_io