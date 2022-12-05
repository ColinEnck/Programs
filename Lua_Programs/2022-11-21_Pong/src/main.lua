function love.load()
	windowWidth, windowHeight = love.graphics.getDimensions()
	love.window.setTitle("Pong - Colin Enck")
	setImages()

	turnCounter = 0

	lRect = {}
	rRect = {}
	setPaddles()

	ball = {}
	resetBall()

	keys = {}

	leftScore = 0
	rightScore = 0
end

function setImages()
	images = {}
	images[0] = love.graphics.newImage("0.png")
	images[1] = love.graphics.newImage("1.png")
	images[2] = love.graphics.newImage("2.png")
	images[3] = love.graphics.newImage("3.png")
	images[4] = love.graphics.newImage("4.png")
	images[5] = love.graphics.newImage("5.png")
	images[6] = love.graphics.newImage("6.png")
	images[7] = love.graphics.newImage("7.png")
	images[8] = love.graphics.newImage("8.png")
	images[9] = love.graphics.newImage("9.png")
end

function setPaddles()
	lRect.x = 50
	lRect.y = 100
	lRect.width = 25
	lRect.height = 100
	
	rRect.x = windowWidth - 50
	rRect.y = 100
	rRect.width = 25
	rRect.height = 100
end

function resetBall()
	ball.x = windowWidth / 2
	ball.y = windowHeight / 3
	ball.radius = 10
	if turnCounter % 2 == 0 then
		ball.dx = 1
	elseif turnCounter % 2 == 1 then
		ball.dx = -1
	end
	ball.dy = -1
end

function setKeys(dir)
	keys[dir] = love.keyboard.isDown(dir);
end

function movePaddle(dt)
	setKeys("w")
	if keys.w and lRect.y >= 0 then
		lRect.y = lRect.y - 250 * dt
	end

	setKeys("s")
	if keys.s and lRect.y <= windowHeight - lRect.height then
		lRect.y = lRect.y + 250 * dt
	end

	setKeys("up")
	if keys.up and rRect.y >= 0 then
		rRect.y = rRect.y - 250 * dt
	end

	setKeys("down")
	if keys.down and rRect.y <= windowHeight - rRect.height then
		rRect.y = rRect.y + 250 * dt
	end
end

function updateBall(dt)
	if ball.dx > 0 then
		ball.x = ball.x + 400 * dt
	elseif ball.dx < 0 then
		ball.x = ball.x - 400 * dt
	end

	if ball.dy > 0 then
		ball.y = ball.y + 400 * dt
	elseif ball.dy < 0 then
		ball.y = ball.y - 400 * dt
	end
end

function ballCollisionPaddle()
	if ball.x <= (lRect.x + lRect.width) and ball.y >= lRect.y and ball.y <= (lRect.y + lRect.height) then
		if ball.x < lRect.x then
			return
		else 
			ball.dx = -(ball.dx)
		end
	elseif ball.x >= rRect.x and ball.y >= rRect.y and ball.y <= (rRect.y + rRect.height) then
		if ball.x > (rRect.x + rRect.width) then
			return
		else
			ball.dx = -(ball.dx)
		end
	end
end

function ballCollisionFloorCeiling()
	if ball.y <= 0 then
		ball.dy = -(ball.dy)
	elseif ball.y >= windowHeight - ball.radius then
		ball.dy = -(ball.dy)
	end
end

function ballCollisionEnds()
	if ball.x <= 0 then
		resetBall()
		rightScore = rightScore + 1
	elseif ball.x >= windowWidth then
		resetBall()
		leftScore = leftScore + 1
	end
	turnCounter = turnCounter + 1
end

function drawScore()
	love.graphics.draw(images[leftScore], 200, 50)
	love.graphics.draw(images[rightScore], windowWidth - (200 + 100), 50)
end

function love.update(dt)
	movePaddle(dt)
	updateBall(dt)
	ballCollisionPaddle()
	ballCollisionFloorCeiling()
	ballCollisionEnds()
	if leftScore == 10 or rightScore == 10 then
		love.event.quit(0)
	end
end

function love.draw()
	love.graphics.rectangle("fill", lRect.x, lRect.y, lRect.width, lRect.height)
	love.graphics.rectangle("fill", rRect.x, rRect.y, rRect.width, rRect.height)
	love.graphics.circle("line", ball.x, ball.y, ball.radius)
	drawScore()
end