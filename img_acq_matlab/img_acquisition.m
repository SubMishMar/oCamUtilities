clear all
clc
cam = webcam('oCam-1CGN-U');
preview(cam);
i = 1;
while(1)
    ip = input('Press 1 (+ Enter) to exit, any other digit (+Return) to continue taking shots:');
    if ip == 1
        clear('cam');
        break;
    else
        if i == 1
            [c tf] = clock;
            foldername = strcat('img',...
                                num2str(c(1)),num2str(c(2)),...
                                num2str(c(3)),num2str(c(4)),...
                                num2str(c(5)),num2str(c(6)));
            mkdir(foldername)
        end
        
        img = snapshot(cam);
        img = rgb2gray(img);
        imwrite(img,strcat(foldername,sprintf('/img_%04d.png',i)));
        i = i + 1;
    end
end


