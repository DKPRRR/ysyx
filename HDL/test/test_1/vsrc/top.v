module top(
    input  wire [1:0] x [3:0],
    input  wire [1:0] y      ,
    output wire [1:0] f
);
    always@(*) begin
        case(y)
            2'b00 : f[1:0] = x[0][1:0];
            2'b01 : f[1:0] = x[1][1:0];
            2'b10 : f[1:0] = x[2][1:0];
            2'b11 : f[1:0] = x[3][1:0];
        endcase
    end
endmodule
