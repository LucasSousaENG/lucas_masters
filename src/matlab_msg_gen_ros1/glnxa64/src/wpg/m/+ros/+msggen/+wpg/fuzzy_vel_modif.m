
classdef fuzzy_vel_modif < ros.Message
    %fuzzy_vel_modif MATLAB implementation of wpg/fuzzy_vel_modif
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'wpg/fuzzy_vel_modif' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '2387584165a79fa8903721b2c12404b6' % The MD5 Checksum of the message definition
        PropertyList = { 'Header' 'DistanceToObstacle' 'DistanceToObjective' 'Velocity' } % List of non-constant message properties
        ROSPropertyList = { 'header' 'distance_to_obstacle' 'distance_to_objective' 'velocity' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.std_msgs.Header' ...
            '' ...
            '' ...
            '' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Header
        DistanceToObstacle
        DistanceToObjective
        Velocity
    end
    methods
        function set.Header(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Header'};
            validateattributes(val, validClasses, validAttributes, 'fuzzy_vel_modif', 'Header')
            obj.Header = val;
        end
        function set.DistanceToObstacle(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'fuzzy_vel_modif', 'DistanceToObstacle');
            obj.DistanceToObstacle = double(val);
        end
        function set.DistanceToObjective(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'fuzzy_vel_modif', 'DistanceToObjective');
            obj.DistanceToObjective = double(val);
        end
        function set.Velocity(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'fuzzy_vel_modif', 'Velocity');
            obj.Velocity = double(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.wpg.fuzzy_vel_modif.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.wpg.fuzzy_vel_modif(strObj);
        end
    end
end