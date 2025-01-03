function [data, info] = vehicle_smc_gains
%vehicle_smc_gains gives an empty data for wpg/vehicle_smc_gains
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'wpg/vehicle_smc_gains';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.Timestamp, info.Timestamp] = ros.internal.ros.messages.ros.default_type('uint64',1);
[data.TimestampSample, info.TimestampSample] = ros.internal.ros.messages.ros.default_type('uint64',1);
[data.KGains, info.KGains] = ros.internal.ros.messages.ros.default_type('single',3);
[data.BetaGains, info.BetaGains] = ros.internal.ros.messages.ros.default_type('single',3);
[data.LambdaGains, info.LambdaGains] = ros.internal.ros.messages.ros.default_type('single',3);
info.MessageType = 'wpg/vehicle_smc_gains';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,11);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'timestamp';
info.MatPath{8} = 'timestamp_sample';
info.MatPath{9} = 'k_gains';
info.MatPath{10} = 'beta_gains';
info.MatPath{11} = 'lambda_gains';
