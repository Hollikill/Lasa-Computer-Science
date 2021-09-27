var weekdays = ["Sunday", "Monday", "Tuesdau", "wendesy", "rthuerday", "frdai", "dstaday"]

$(function() {
    for (var i = 0; i < 7; i++) {
        var newhead = document.createElement("div");
        newhead.classList.add("header");
        newhead.textContent = weekdays[i];

        if (i==0) {
            newhead.classList.add("startline");
        }

        $("#month").append(newhead);
    }
    for (var i = 0; i < 31; i++) {
        var newday = document.createElement("div");
        newday.classList.add("day");
        newday.textContent = i+1;

        if ((i%7)==0) {
            newday.classList.add("startline");
        }

        $("#month").append(newday);
    }
    $(".day").hover(function () {
            if (!$(this).hasClass("clicked")) {
                r = (127*Math.random())+128;
                g = (127*Math.random())+128;
                b = (127*Math.random())+128;

                $(this).css("background-color", "rgb("+r+", "+g+", "+b+")");
                $(this).css("border-color", "rgb("+(r/2)+", "+(g/2)+", "+(b/2)+")");
            }
        }, function () {
            if (!$(this).hasClass("clicked")) {
                $(this).css("background-color", "white");
                $(this).css("border-color", "lightgray");
            }
        }
    );
    $(".day").click(function (e) { 
        e.preventDefault();

        $(".clicked").css("background-color", "white");
        $(".clicked").css("border-color", "lightgray");
        $(".clicked").removeClass("clicked");

        $(this).css("background-color", "darkgray");
        $(this).css("border-color", "black");
        $(this).addClass("clicked");
    });
});