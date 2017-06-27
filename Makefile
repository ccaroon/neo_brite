neo_brite.bin: project.properties src/* lib/*
	mkdir build
	cp project.properties src/* lib/* build/
	particle compile photon build/ --saveTo neo_brite.bin
	rm -rf build/

flash: neo_brite.bin
	particle flash RedRover neo_brite.bin

clean:
	rm -rf neo_brite.bin build/
