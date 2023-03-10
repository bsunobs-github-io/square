import unittest
import ROOT


class STL_vector(unittest.TestCase):
    """
    Tests for the pythonizations of std::vector. 
    """

    def test_vec_char_data(self):
        '''
        Test that calling std::vector<char>::data() returns a Python string
        that contains the characters of the vector and no exception is raised.
        Check also that the iteration over the vector runs normally (#9632).
        '''

        elems = ['a','b','c']
        v = ROOT.std.vector['char'](elems)
        self.assertEqual(v.data(), ''.join(elems))

        for elem in v:
            self.assertEqual(elem, elems.pop(0))

    def test_vec_const_char_p(self):
        '''
        Test that creating a std::vector<const char*> does not raise any
        exception (#11581).
        '''
        ROOT.std.vector['const char*']()


if __name__ == '__main__':
    unittest.main()
