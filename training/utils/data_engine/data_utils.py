def read_file_to_string(file_path):
    """
    @file_path: the path of the Fortran or CPP file to be read
    @return: the string of the file
    Example:
        fp = "data/fortran/fortran_code.f90"
        fortran_code = read_file_to_string(fp)
    """
    with open(file_path, 'r') as f:
        return f.read()


