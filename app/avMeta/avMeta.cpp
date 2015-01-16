#include <AvTranscoder/file/InputFile.hpp>
#include <AvTranscoder/mediaProperty/print.hpp>

#include <AvTranscoder/progress/NoDisplayProgress.hpp>

#include <iostream>

int main( int argc, char** argv )
{
	if( argc != 2 )
	{
		std::cout << "avmeta require a media filename" << std::endl;
		return( -1 );
	}

	avtranscoder::preloadCodecsAndFormats();

	// analyse inputFile
	avtranscoder::InputFile input( argv[1] );
	avtranscoder::NoDisplayProgress p;
	input.analyse( p, avtranscoder::eAnalyseLevelFirstGop );

	// display file properties
	std::cout << input;
}
