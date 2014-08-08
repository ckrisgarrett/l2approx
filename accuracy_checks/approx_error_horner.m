% Approximates the error for the different polynomial approximations.
% The polynomials are evaluated using Horner's method.
function [result] = approx_error_horner()

result = zeros(12,6);

for x = -3.14:.01:3.14
    % sin
    approx = sinPiHorner(x);
    for i = 1:12
        if abs(approx(i) - sin(x)) > result(i,1)
            result(i,1) = abs(approx(i) - sin(x));
        end
    end
    
    % cos
    approx = cosPiHorner(x);
    for i = 1:12
        if abs(approx(i) - cos(x)) > result(i,2)
            result(i,2) = abs(approx(i) - cos(x));
        end
    end
end


for x = (-3.14 / 2):.01:(3.14 / 2)
    % sin
    approx = sinPi2Horner(x);
    for i = 1:12
        if abs(approx(i) - sin(x)) > result(i,3)
            result(i,3) = abs(approx(i) - sin(x));
        end
    end
    
    % cos
    approx = cosPi2Horner(x);
    for i = 1:12
        if abs(approx(i) - cos(x)) > result(i,4)
            result(i,4) = abs(approx(i) - cos(x));
        end
    end
end


for x = (-3.14 / 4):.01:(3.14 / 4)
    % sin
    approx = sinPi4Horner(x);
    for i = 1:12
        if abs(approx(i) - sin(x)) > result(i,5)
            result(i,5) = abs(approx(i) - sin(x));
        end
    end
    
    % cos
    approx = cosPi4Horner(x);
    for i = 1:12
        if abs(approx(i) - cos(x)) > result(i,6)
            result(i,6) = abs(approx(i) - cos(x));
        end
    end
end


end