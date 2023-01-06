function setImages(filename)
	images[filename] = love.graphics.newImage(filename .. ".png")
end

function startOfTheGame()
	
end

function love.load()
	PIXEL_LEN = 16
	X_LEN = 40
	Y_LEN = 40
	windowSuccess = love.window.setMode(X_LEN * PIXEL_LEN, Y_LEN * PIXEL_LEN)
	if windowSuccess == 0 then os.exit(1) end

	local filenames = {
		"a",
		"d",
		"h",
		"s",
		"v", 
		"w",
	}
	images = {}
	for i=1, table.getn(filenames) do
		setImages(filenames[i])
	end
	
	
end

function love.update(dt)

end

function love.draw()

end