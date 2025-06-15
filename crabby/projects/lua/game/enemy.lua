-- enemy.lua
local map = require("map")
local enemy = {}

function enemy.load()
    enemy.x = 100
    enemy.y = 100
    enemy.speed = 100
    enemy.vision_range = 200
    enemy.fovAngle = math.pi / 2
    enemy.facing = 0
    enemy.alive = true
    enemy.canSeePlayer = false

    enemy.pickNewTarget()

    -- enemy.patrolPoints = {
    --     {x = 100, y = 100},
    --     {x = 700, y = 100}
    -- }
    -- enemy.currentTarget = 1
    enemy.delay = 2
    enemy.timer = 0
end

function enemy.update(dt, playerX, playerY)
    if not enemy.alive then return end

    -- Delay before tracking
    enemy.timer = enemy.timer + dt
    if enemy.timer >= enemy.delay then
        local dx = enemy.targetX - enemy.x
        local dy = enemy.targetY - enemy.y
        local dist = math.sqrt(dx * dx + dy * dy)

        if dist > 1 then
            local dirX, dirY = dx / dist, dy / dist
            enemy.facing = math.atan2(dy, dx)
            local newX = enemy.x + dirX * enemy.speed * dt
            local newY = enemy.y + dirY * enemy.speed * dt
            if not map.isBlocked(newX, enemy.y) then
                enemy.x = newX
            end
            if not map.isBlocked(enemy.x, newY) then
                enemy.y = newY
            end
        else
            enemy.pickNewTarget()
        end
        local pdx = playerX - enemy.x
        local pdy = playerY - enemy.y
        local pdist = math.sqrt(pdx * pdx + pdy * pdy)

        if pdist < enemy.vision_range then
            local angleToPlayer = math.atan2(pdy, pdx)
            local angleDiff = math.abs((angleToPlayer - enemy.facing + math.pi) % (2 * math.pi) - math.pi)

            if angleDiff < enemy.fovAngle / 2 then
                enemy.canSeePlayer = true
            else
                enemy.canSeePlayer = false
            end
        else
            enemy.canSeePlayer = false
        end
    else
        enemy.canSeePlayer = false
    end
end

function enemy.draw()
    if not enemy.alive then return end
    love.graphics.setColor(1, 1, 0, 0.2)
    love.graphics.arc(
        "fill",
        enemy.x,
        enemy.y,
        enemy.vision_range,
        enemy.facing - enemy.fovAngle / 2, 
        enemy.facing + enemy.fovAngle / 2
    )
    love.graphics.setColor(1, 1, 0)
    love.graphics.rectangle("fill", enemy.x - 15, enemy.y - 15, 30, 30)
end

function enemy.pickNewTarget()
    enemy.targetX = love.math.random(50, love.graphics.getWidth() - 50)
    enemy.targetY = love.math.random(50, love.graphics.getHeight() - 50)
end

return enemy
