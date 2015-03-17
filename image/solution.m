img = imread('spring.png');
img = img(:, :, 1);

imshow(img ~= hex2dec('5A'), []);
