% Approximates the error for the different polynomial approximations.
function [result] = approx_error()

result = zeros(12,6);

for x = -3.14:.01:3.14
    % sin
    approx = sinPi(x);
    for i = 1:12
        if abs(approx(i) - sin(x)) > result(i,1)
            result(i,1) = abs(approx(i) - sin(x));
        end
    end
    
    % cos
    approx = cosPi(x);
    for i = 1:12
        if abs(approx(i) - cos(x)) > result(i,2)
            result(i,2) = abs(approx(i) - cos(x));
        end
    end
end


for x = (-3.14 / 2):.01:(3.14 / 2)
    % sin
    approx = sinPi2(x);
    for i = 1:12
        if abs(approx(i) - sin(x)) > result(i,3)
            result(i,3) = abs(approx(i) - sin(x));
        end
    end
    
    % cos
    approx = cosPi2(x);
    for i = 1:12
        if abs(approx(i) - cos(x)) > result(i,4)
            result(i,4) = abs(approx(i) - cos(x));
        end
    end
end


for x = (-3.14 / 4):.01:(3.14 / 4)
    % sin
    approx = sinPi4(x);
    for i = 1:12
        if abs(approx(i) - sin(x)) > result(i,5)
            result(i,5) = abs(approx(i) - sin(x));
        end
    end
    
    % cos
    approx = cosPi4(x);
    for i = 1:12
        if abs(approx(i) - cos(x)) > result(i,6)
            result(i,6) = abs(approx(i) - cos(x));
        end
    end
end

end